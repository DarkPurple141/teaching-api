#!/usr/bin/env python3.5

import os, logging
from flask import Flask, request, session, g, redirect, url_for, abort, \
     render_template, jsonify, send_from_directory

from model import FileParser
from config import BaseConfig

app = Flask(__name__)
app.config.from_object(BaseConfig)

# Load default config and override config from an environment variable
app.config.from_envvar('API_SETTINGS', silent=True)
handler = logging.FileHandler(app.config['LOGGING_LOCATION'])
handler.setLevel(app.config['LOGGING_LEVEL'])
formatter = logging.Formatter(app.config['LOGGING_FORMAT'])
handler.setFormatter(formatter)
app.logger.addHandler(handler)

@app.after_request
def incoming(response):
    header = response.headers
    header['Access-Control-Allow-Origin'] = '*'
    return response

@app.route('/api')
def test():
    return jsonify(msg="Hello")

# serve 'meta' file
@app.route('/api/labs/<week>/meta.json')
def sendMeta(week):
    return send_from_directory("labs/{}/".format(week), 'meta.json')

@app.route('/api/labs/meta/')
def sendDescriptors():
    f = FileParser('labs/')
    return [ jsonify(f.openFile(os.path.join(meta['path'], 'meta.json'))) for meta in f.files ]

@app.route('/api/labs')
def serveLabs():
    f = FileParser('labs/')
    return(jsonify(results=f.sendFiles()))

@app.route('/api/labs/<week>')
def serveWeek(week):
    f = FileParser('labs/{}'.format(week))
    res = {}
    for fp in f.files:
        if fp['name'] == "meta.json":
            continue
        res[fp['name']] = {
                'code': f.openFile(fp['path']),
                'name': fp['name']
            }

    return(jsonify(res))

@app.route('/api/notes')
def serveNotes():
    return "Notes are a comin'"

@app.route('/')
def serve():
    return "This is an API server."
