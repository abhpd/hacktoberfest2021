"""
    Ted Talk Downloader
    - The script helps you in downloading any ted talk by providing the url
    
    Author : yash
    Date : 08/10/21

"""

import requests
from bs4 import BeautifulSoup
import sys
import re

if len(sys.argv) > 1:
    url = sys.argv[1]
else:
    sys.exit('Please enter the ted talk url')

# url = 'https://www.ted.com/talks/devin_shuman_the_genes_you_don_t_get_from_your_parents_but_can_t_live_without'

data = requests.get(url)

print('======================================Download is about to start==========================')

soup = BeautifulSoup(data.content, features="lxml")

for val in soup.findAll('script'):
    if re.search('talkPage.init', str(val)) is not None:
        result = str(val)

result_mp4 = re.search('(?P<url>https://[^\s]+)(mp4)', result).group('url')

finalUrl = result_mp4.split('"')[0]

print("Downloading video from ..." + finalUrl)

fileName = finalUrl.split('/')[len(finalUrl.split('/'))-1].split('?')[0]

print(f'Storing the video in the file: {fileName}')

downloadedVideo = requests.get(finalUrl)

with open(fileName,'wb') as f:
    f.write(downloadedVideo.content)


print("=======================Download Finished============================")