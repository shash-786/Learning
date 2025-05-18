#!/usr/bin/python3
# Copyright 2010 Google Inc.
# Licensed under the Apache License, Version 2.0
# http://www.apache.org/licenses/LICENSE-2.0

# Google's Python Class
# http://code.google.com/edu/languages/google-python-class/

import os
import re
import sys
import urllib.request

from bs4 import BeautifulSoup

"""Logpuzzle exercise
Given an apache logfile, find the puzzle urls and download the images.

Here's what a puzzle url looks like:
10.254.254.28 - - [06/Aug/2007:00:13:48 -0700] "GET /~foo/puzzle-bar-aaab.jpg HTTP/1.0" 302 528 "-" "Mozilla/5.0 (Windows; U; Windows NT 5.1; en-US; rv:1.8.1.6) Gecko/20070725 Firefox/2.0.0.6"
"""


def read_urls(filename):
    """
        Returns a list of the puzzle urls from the given log file,
        extracting the hostname from the filename itself.
        Screens out duplicate urls and returns the urls sorted into
    increasing order.
    """
    urls: list[str] = []
    with open(file=filename, mode="r") as file:
        content: str = file.read()
        baseurl: str = "http://code.google.com"
        pat: str = r'"GET (.*?puzzle.*?) HTTP/1.0"'

        paths: list[str] = re.findall(pat, content)
        for path in paths:
            url = baseurl + path
            urls.append(url)
    return urls


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
    img_urls = sorted(img_urls)
    if todir:
        download_images(img_urls, todir)
    else:
        print("\n".join(img_urls))


if __name__ == "__main__":
    main()
