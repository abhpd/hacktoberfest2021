// Author : Adwait Patil
const Discord = require('discord.js');
const api = require("imageapi.js");
const fetch = require("node-fetch")
const client = new Discord.Client();

client.on('ready', () => {
    client.user.setStatus('available')
    client.user.setPresence({
        game: {
            name: 'with your mind',
        }
    });
});

const reddit = 'https://www.reddit.com/r/';
const memetext = 'A meme from r/'
client.on('message', async msg => {
  if ((msg.content === 'meme')) {
    let subreddits = [
      "memes","dankmemes"
    ];
    let subreddit = subreddits[Math.floor(Math.random()*(subreddits.length))];
    let img = await api(subreddit)
    const Embed = new Discord.MessageEmbed()
    .setTitle(memetext.concat(subreddit))
    .setURL(reddit.concat(subreddit))
    .setColor('RANDOM')
    .setImage(img)
    msg.channel.send(Embed)
  }
});
client.login(token) //use your own token here.
