#!/usr/bin/env python3

from wsgiref.handlers import CGIHandler
from api import app

if __name__ == '__main__':
   CGIHandler().run(app)
