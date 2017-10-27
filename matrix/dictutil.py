# Copyright 2013 Philip N. Klein
def dict2list(dct, keylist): return [ dct[i] for i in keylist ]

def list2dict(L, keylist):  return { key:l for (key, l) in zip(keylist, L) }

def listrange2dict(L): return {l:i for (l, i) in zip(range(0, len(L)), L)}
