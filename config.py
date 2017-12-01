
import logging

class BaseConfig(object):
    USERNAME='admin'
    PASSWORD='default'
    DEBUG = False
    TESTING = False
    SECRET_KEY = '1d94e52c-1c89-4515-b87a-f48cf3cb7f0b'
    LOGGING_FORMAT = '%(asctime)s - %(name)s - %(levelname)s - %(message)s'
    LOGGING_LOCATION = 'server.log'
    LOGGING_LEVEL = logging.DEBUG
