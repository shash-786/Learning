#!/usr/bin/python3
# Copyright 2010 Google Inc.
# Licensed under the Apache License, Version 2.0
# http://www.apache.org/licenses/LICENSE-2.0

# Google's Python Class
# http://code.google.com/edu/languages/google-python-class/

import sys
import re
import os
import shutil
import subprocess

"""Copy Special exercise
"""

# +++your code here+++
# Write functions and modify main() to call them
def list_special_files(directory: str):
  entries: list[os.DirEntry] = os.scandir(directory)
  specialFiles: list[str] = []
  for entry in entries:
    if entry.is_dir():
      specialFiles.extend(list_special_files(entry.path))
    else:
      name: str = entry.name
      pat: str = r'.*?__[a-zA-Z]+__.*?'
      if re.search(pattern=pat, string=name):
        specialFiles.append(os.path.abspath(entry.path))
  return specialFiles


def main():
  # This basic command line argument parsing code is provided.
  # Add code to call your functions below.

  # Make a list of command line arguments, omitting the [0] element
  # which is the script itself.
  args = sys.argv[1:]
  if not args:
    print('usage: [--todir dir][--tozip zipfile] dir [dir ...]')
    sys.exit(1)

  # todir and tozip are either set from command line
  # or left as the empty string.
  # The args array is left just containing the dirs.
  todir = ''
  if args[0] == '--todir':
    todir = args[1]
    del args[0:2]

  tozip = ''
  if args[0] == '--tozip':
    tozip = args[1]
    del args[0:2]

  if not args: # A zero length array evaluates to "False".
    print('error: must specify one or more dirs')
    sys.exit(1)

  # +++your code here+++
  # Call your functions
  dir: str = args[0]
  specialFiles: list[str] = list_special_files(dir)
  if todir != '':
    pass
  elif tozip != '':
    pass
  else:
    for file in specialFiles:
      print(file)

if __name__ == '__main__':
  main()
