#!/usr/local/bin/python3.5

import os, markdown

class FileParser(object):
    """docstring for FileParser"""
    def __init__(self, path):
        super(FileParser, self).__init__()
        self.path = path
        self.files = []
        self._populate()

    def _populate(self):
        self.files = [{
            'name': i,
            'path': os.path.join(self.path, i)}
            for i in os.listdir(os.path.join(os.path.dirname(__file__), self.path))
        ]

    def openFile(self, file):
        with open(file, mode='r', encoding="utf-8") as fo:
            return fo.read()

    def sendProperNames(self):
        return [{
                    'path': i['path'],
                    'name': "Week {}".format(i['name'][4:]),
                    'file': i['name']
                } for i in self.files
                ]

    def renderCode(self, file):
        return markdown.markdown('```language-c\n{}\n```'.format(self.openFile(file)), extensions=['fenced_code'])

    def renderMD(self, file):
        return markdown.markdown(self.openFile(file), extensions=['fenced_code'])

if __name__ == '__main__':
    f = FileParser('labs/{}'.format('week1'))
    res = {}
    for fp in f.files:
        if fp['name'] == "meta" or fp['name'] == 'a.out':
            continue
        res[fp['name']] = {
                'code': f.openFile(fp['path']),
                'name': fp['name']
            }
    print(res)
