#ifndef HTML_CONTENT_H
#define HTML_CONTENT_H

const char MAIN_PAGE[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html>
  <head>
    <title>Digital Library</title>
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <style>
      body {
        font-family: 'Courier New', Courier, monospace;
        margin: 0;
        padding: 20px;
        background-color: #000;
        color: #5df2bd;
        line-height: 1.4;
      }

      .container {
        max-width: 1000px;
        margin: 0 auto;
        background: #000;
        padding: 30px;
        border: 2px solid #00b8ff;
        border-radius: 4px;
        box-shadow: 0 0 20px rgba(0, 255, 255, 0.2),
          inset 0 0 20px rgba(0, 255, 255, 0.2);
        position: relative;

        /* Overflow hidden to hide the scanline */
        overflow: hidden;
      }

      h1 {
        color: #00b8ff;
        text-align: left;
        border-bottom: 1px solid #00b8ff;
        margin-bottom: 30px;
        font-weight: normal;
        font-size: 2.5em;
        text-transform: uppercase;
        letter-spacing: 2px;
        text-shadow: 0 0 10px rgba(0, 255, 255, 0.5);
      }

      .book-grid {
        display: grid;
        grid-template-columns: repeat(auto-fill, minmax(250px, 1fr));
        gap: 20px;
        margin-top: 30px;
      }

      .book-card {
        /* background: rgba(0, 255, 255, 0.05); */
        background: rgba(0, 20, 0, 0.8);
        border: 1px solid #00b8ff;
        padding: 20px;
        position: relative;
        cursor: pointer;
      }

      .book-card:hover {
        background: rgba(0, 255, 255, 0.1);
      }

      .book-title {
        font-size: 1.4em;
        margin-bottom: 8px;
        color: #5df2bd;
      }

      .book-title::after {
        content: '_';
        animation: blink 1s infinite;
      }

      .book-author {
        color: #3da592;
        font-size: 1.1em;
        margin-bottom: 15px;
      }

      .read-button {
        font-family: 'Courier New', Courier, monospace;
        display: inline-block;
        padding: 8px 16px;
        background: transparent;
        color: #00b8ff;
        text-decoration: none;
        border: 1px solid #00b8ff;
        font-size: 1.1em;
        transition: all 0.3s ease;
        text-transform: uppercase;
      }

      .story-content {
        display: none;
        padding: 15px;
        margin-top: 15px;
        border-top: 1px solid rgba(0, 255, 255, 0.3);
        white-space: pre-line;
      }

      .story-content.active {
        display: block;
      }

      .footer {
        text-align: center;
        margin-top: 30px;
        padding-top: 20px;
        border-top: 1px solid rgba(0, 255, 255, 0.3);
        color: #5df2bd;
        font-size: 1em;
      }

      .system-info {
        position: absolute;
        top: 10px;
        right: 10px;
        font-size: 0.9em;
        color: #00b8ff;
      }

      @media (max-width: 600px) {
        body {
          padding: 10px;
        }
        .book-grid {
          grid-template-columns: 1fr;
        }
        h1 {
          font-size: 1.8em;
        }
      }

      @keyframes blink {
        0% {
          opacity: 0;
        }
        49% {
          opacity: 0;
        }
        50% {
          opacity: 1;
        }
        100% {
          opacity: 1;
        }
      }

      @keyframes scanline {
        0% {
          transform: translateY(-100%);
        }
        100% {
          transform: translateY(5000%);
        }
      }
      .scanline {
        position: absolute;
        top: 2%;
        left: 0;
        width: 100%;
        height: 20px;
        background: linear-gradient(
          to bottom,
          transparent,
          rgba(0, 184, 255, 0.2),
          transparent
        );
        animation: scanline 15s linear infinite;
        pointer-events: none;
        z-index: 1;
      }
    </style>
  </head>
  <body>
    <div class="container">
      <div class="scanline"></div>

      <div class="system-info">
        SYSTEM.ID: LIB-7675
        <br />
        TIME: <span id="system-time">00:00:00</span>
      </div>

      <h1>DIGITAL LIBRARY</h1>

      <div class="book-grid" id="bookGrid">
        <!-- Stories will be inserted here via JavaScript -->
      </div>

      <div class="footer">SYSTEM VERSION: 1.0.0</div>
    </div>

    <script>
      function updateTime() {
        const now = new Date();
        const time = now.toTimeString().split(' ')[0];
        document.getElementById('system-time').textContent = time;
      }

      setInterval(updateTime, 1000);
      updateTime();

      const bookGrid = document.getElementById('bookGrid');

      // Load and display stories
      const stories = STORIES;

      stories.forEach((story, index) => {
        const card = document.createElement('div');
        card.className = 'book-card';
        card.innerHTML = `
          <div class="book-title">${story.title}</div>
          <div class="book-author">${story.author}</div>
          ${
            story.hasFullVersion
              ? `<a href="/book?id=${story.id}" class="read-button">Access Data</a>`
              : `<button class="read-button" onclick="toggleStory(${index})">Show Data</button>`
          }
          ${
            !story.hasFullVersion
              ? `<div class="story-content">${story.content}</div>`
              : ''
          }
        `;
        bookGrid.appendChild(card);
      });

      function toggleStory(index) {
        const bookCards = document.querySelectorAll('.book-card');
        bookCards.forEach((card, i) => {
          const storyContent = card.querySelector('.story-content');
          if (i === index && storyContent) {
            storyContent.classList.toggle('active');
          } else if (storyContent) {
            storyContent.classList.remove('active');
          }
        });
      }
    </script>
  </body>
</html>
)rawliteral";

#endif