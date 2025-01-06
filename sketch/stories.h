#ifndef STORIES_H
#define STORIES_H

extern const char STORIES_JS[] PROGMEM = R"rawliteral(
const STORIES = [
  {
    "title": "The Raven",
    "author": "EDGAR ALLEN POE",
    "content": "https://poestories.com/read/raven",
    "hasFullVersion": true,
    "id": "raven"
  },
  {
    title: "THE ROAD NOT TAKEN",
    author: "ROBERT FROST",
    content: `Two roads diverged in a yellow wood,
And sorry I could not travel both
And be one traveler, long I stood
And looked down one as far as I could
To where it bent in the undergrowth;

Then took the other, as just as fair,
And having perhaps the better claim,
Because it was grassy and wanted wear;
Though as for that the passing there
Had worn them really about the same,

And both that morning equally lay
In leaves no step had trodden black.
Oh, I kept the first for another day!
Yet knowing how way leads on to way,
I doubted if I should ever come back.

I shall be telling this with a sigh
Somewhere ages and ages hence:
Two roads diverged in a wood, and I—
I took the one less traveled by,
And that has made all the difference.`,
    "hasFullVersion": false
  },
  {
    "title": "The Water-Lily Pond",
    "author": "Claude Monet",
    "content": "https://commons.wikimedia.org/wiki/File:The_Water-Lily_Pond_-_Google_Arts_%26_Culture.jpg",
    "hasFullVersion": true,
    "id": "monet"
  },
  {
    "title": "Symphony No. 40",
    "author": "Wolfgang Amadeus Mozart",
    "content": "https://www.chosic.com/download-audio/25966/",
    "hasFullVersion": true,
    "id": "mozart"
  }
];
)rawliteral";

#endif