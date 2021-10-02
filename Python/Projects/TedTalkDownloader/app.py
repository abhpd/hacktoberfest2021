import requests
from bs4 import BeautifulSoup
import re
import sys

if len(sys.argv) > 1:
    url = sys.argv[1]
else:
    sys.exit("Error: Please enter the correct URL")

r = requests.get(url)

print("Download is about to start")

soup = BeautifulSoup(r.content, features="lxml")

for val in soup.findAll("script"):
    if(re.search("talkPage.init", str(val))) is not None:
        result = str(val)

resultMp4 = re.search("(?P<url>https?://[^\s]+)(mp4)", result).group("url")
mp4Url = resultMp4.split('"')[0]

print("Downloading starting from " + mp4Url)

fileName = mp4Url.split("/")[len(mp4Url.split("/"))-1].split('?')[0]

print("Storing video in " + fileName)

r = requests.get(mp4Url)

with open(fileName, 'wb') as f:
    f.write(r.content)

print("Download process is finished")
