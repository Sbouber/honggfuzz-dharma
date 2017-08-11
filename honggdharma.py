from core.dharma import DharmaMachine
import struct
import random
import os
import logging
import sys

sys.setrecursionlimit(20000)
random.seed(struct.unpack('q', os.urandom(8))[0])
dharmagen = DharmaMachine()
dharmagen.process_settings(open('settings.py', 'r'))
dharmagen.process_grammars([open('grammar.dg', 'r')])


def generate():
   global dharmagen

   return dharmagen.generate_content()
