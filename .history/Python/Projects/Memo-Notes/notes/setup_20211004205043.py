from setuptools import setup

setup(
    name='notes',
    packages=["notes"],
    version='0.11.0',
    description='Creating sticky notes has never been easier.',
    long_desciption='A simple GUI sticky note program created with tkinter.',
    author='GrgBls',
    author_email='grgbls647@gmail.com',
    url='https://github.com/GrgBls/noty',
    license='MIT',
    py_modules=['notes'],
    install_requires=[''],
    entry_points='''
        [console_scripts]
        noty=noty.main:cli
    ''',
)
