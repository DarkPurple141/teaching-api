#!/usr/local/bin/python3.5

from wsgiref.handlers import CGIHandler
from api import app

if __name__ == '__main__':
   CGIHandler().run(app)
