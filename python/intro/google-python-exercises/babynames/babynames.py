#!/usr/bin/python3
# Copyright 2010 Google Inc.
# Licensed under the Apache License, Version 2.0
# http://www.apache.org/licenses/LICENSE-2.0

# Google's Python Class
# http://code.google.com/edu/languages/google-python-class/

import sys
import re

"""Baby Names exercise

Define the extract_names() function below and change main()
to call it.

For writing regex, it's nice to include a copy of the target
text for inspiration.

Here's what the html looks like in the baby.html files:
...
<h3 align="center">Popularity in 1990</h3>
....
<tr align="right"><td>1</td><td>Michael</td><td>Jessica</td>
<tr align="right"><td>2</td><td>Christopher</td><td>Ashley</td>
<tr align="right"><td>3</td><td>Matthew</td><td>Brittany</td>
...

Suggested milestones for incremental development:
 -Extract the year and print it
 -Extract the names and rank numbers and just print them
 -Get the names data into a dict and print it
 -Build the [year, 'name rank', ... ] list and print it
 -Fix main() to use the extract_names list
"""

def extract_year(content: str):
  pat: str = r'<h3\s*.*>[A-Za-z ]+(\d+)</h3>'
  year: str = re.search(pat, content)
  if year:
    return year.group(1)
  else:
    print("unable to extract year")
    exit()
  
def extract_names(content: str):
  names: list[str] = []
  html_pattern: str = r'<td>(\d+)</td><td>(.*?)</td><td>(.*?)</td>'
  iterable = re.finditer(html_pattern, content)
  for match in iterable:
    if match:
      rank: int = match.group(1)
      name1: str = match.group(2)
      name2: str = match.group(3)

      if len(name1) < len(name2):
        names.append(name1 + " " + rank)
      else:
        names.append(name2 + " " + rank)
  return names

def extract_info(filename):
  """
  Given a file name for baby.html, returns a list starting with the year string
  followed by the name-rank strings in alphabetical order.
  ['2006', 'Aaliyah 91', Aaron 57', 'Abagail 895', ' ...]
  """
  # +++your code here+++
  ans: str = []
  name_ranked: str = []
  with open(filename, 'r') as file:
    reader: str = file.read()
    year: str = extract_year(reader)
    '''
    tuples = re.findall(r'<td>(\d+)</td><td>(\w+)</td>\<td>(\w+)</td>', reader)
    print(tuples)
    (1, 'boyname', 'girlname')
    '''
    ans.append(year)
    
    name_ranked = extract_names(reader)
    name_ranked.sort()

  return ans + name_ranked

def main():
  # This command-line parsing code is provided.
  # Make a list of command line arguments, omitting the [0] element
  # which is the script itself.
  args = sys.argv[1:]

  if not args:
    print('usage: [--summaryfile] file [file ...]')
    sys.exit(1)

  # Notice the summary flag and remove it from args if it is present.
  summary = False
  if args[0] == '--summaryfile':
    summary = True
    del args[0]

  # +++your code here+++
  # For each filename, get the names, then either print the text output
  # or write it to a summary file
  ans: list[str] = extract_info("baby2006.html")
  for word in ans:
    pass
    #print(word)


if __name__ == '__main__':
  main()
