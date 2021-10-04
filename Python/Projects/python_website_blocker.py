"""
to schedule the job on your linux

crontab -e
it will open a file and you need to add the folowwing line

0 7 * * MON-FRI /usr/bin/python3 ~/desktop/python_website_blocker.py >> ~/cron.log 2>&1
It will launch this script a 7AM each morning from Monday to Friday and log the job in the ~/cron.log file
"""
import time
from datetime import datetime as dt

SITES_TO_BLOCK = [
    'www.instagram.com', 'instagram.com',
    'www.youtube.com', 'youtube.com',
    'www.linkedin.com', 'linkedin.com',
    'www.twitter.com', 'twitter.com',
]

linux_host = '/etc/hosts'
# mac_os_host = '/private/etc/hosts'
# window_host = r"C:\Windows\System32\drivers\etc\hosts"
default_hoster = linux_host
localhost = "127.0.0.1"


def _compare_date_with_working_hour(start_hour: int, end_hour: int) -> bool:
    dt_now = dt.now()
    dt_start_hour = dt(dt_now.year, dt_now.month, dt_now.day, start_hour)
    dt_end_hour = dt(dt_now.year, dt_now.month, dt_now.day, end_hour)
    return dt_start_hour < dt_now < dt_end_hour

def block_websites(start_hour: int, end_hour: int) -> None:
    exit = False
    while not exit:
        with open(default_hoster, 'r+') as hostfile:
            hosts = hostfile.readlines()
            if _compare_date_with_working_hour(start_hour, end_hour):
                print("Working hours 8AM - 5PM")
                for site in SITES_TO_BLOCK:
                    if site not in hosts:
                        hostfile.write(localhost + ' ' + site + "\n")
            else:
                if dt.now().hour >= 17:
                    exit = True
                hostfile.seek(0)
                for host in hosts:
                    if not any(site in host for site in SITES_TO_BLOCK):
                        hostfile.write(host)
                hostfile.truncate()
                print('Personal time')
        time.sleep(10)


if __name__ == '__main__':
    block_websites(8, 17)
