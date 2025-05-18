#!/usr/bin/python3
# Copyright 2010 Google Inc.
# Licensed under the Apache License, Version 2.0
# http://www.apache.org/licenses/LICENSE-2.0

# Google's Python Class
# http://code.google.com/edu/languages/google-python-class/

import sys
import os
import urllib.request
import re

from bs4 import BeautifulSoup

"""Logpuzzle exercise
Given an apache logfile, find the puzzle urls and download the images.

Here's what a puzzle url looks like:
10.254.254.29 - - [06/Aug/2007:00:12:19 -0700] "GET /edu/languages/google-python-class/images/puzzle/p-bija-baei.jpg HTTP/1.0" 200 22950 "-" "Mozilla/5.0 (Windows; U; Windows NT 5.1; en-US; rv:1.8.0.12) Gecko/20070508 Firefox/1.5.0.12"
"""


def url_sort_key(url):
    """Used to order the urls in increasing order by 2nd word if present."""
    match = re.search(r"-(\w+)-(\w+)\.\w+", url)
    if match:
        return match.group(2)
    else:
        return url


# LAB(end solution)


def read_urls(filename):
    """Returns a list of the puzzle urls from the given log file,
    extracting the hostname from the filename itself.
    Screens out duplicate urls and returns the urls sorted into
    increasing order."""
    # +++your code here+++
    # LAB(begin solution)
    # Extract the hostname from the filename
    underbar = filename.index("_")
    host = filename[underbar + 1 :]

    # Store the ulrs into a dict to screen out the duplicates
    url_dict = {}

    with open(filename) as f:
        for line in f:
            # Find the path which is after the GET and surrounded by spaces.
            match = re.search(r'"GET (\S+)', line)
            # Above uses \S (upper case S) which is any non-space char
            # Alternately could use square brackets: "GET ([^ ]+)"
            # or the ? form: "GET (.+?) "

            if match:
                path = match.group(1)
                # Add to dict if it's a special "puzzle" url
                # (could combine this 'puzzle' check with the above GET extraction)
                if "puzzle" in path:
                    url_dict["http://" + host + path] = 1

        return sorted(url_dict.keys(), key=url_sort_key)


def download_images(urls, dest_dir):
    """
    Given the urls already in the correct order, downloads
    each image into the given directory.
    Gives the images local filenames img0, img1, and so on.
    Creates an index.html in the directory
    with an img tag to show each local image file.
    Creates the directory if necessary.
    """
    soup = BeautifulSoup("<html><body></body></html>", "html.parser")
    body = soup.body

    if body is None:
        sys.stderr.write("html body is None")
        sys.exit(1)

    file = open("index.html", "w")

    os.makedirs(dest_dir, exist_ok=True)
    for index, url in enumerate(urls):
        filepath = "./" + dest_dir + "/img" + str(index) + ".jpg"
        print("Retrieving image for url " + url)
        urllib.request.urlretrieve(url, filepath)
        img_tag = soup.new_tag("img", src=filepath)
        body.append(img_tag)

    file.write(str(soup.prettify()))
    file.close()

    print("Successfully created index.html in the root directory.")


def main():
    args = sys.argv[1:]

    if not args:
        print("usage: [--todir dir] logfile ")
        sys.exit(1)

    todir = ""
    if args[0] == "--todir":
        todir = args[1]
        del args[0:2]

    img_urls = read_urls(args[0])
    img_urls = sorted(img_urls, key=url_sort_key)
    if todir:
        download_images(img_urls, todir)
    else:
        print("\n".join(img_urls))


if __name__ == "__main__":
    main()
