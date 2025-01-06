const char BOOK_PAGE[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html>
  <head>
    <title>Time Machine - Digital Archive</title>
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <style>
      body {
        font-family: 'Courier New', Courier, monospace;
        margin: 0;
        padding: 20px;
        background-color: #000;
        color: #5df2bd;
        line-height: 1.6;
      }

      .container {
        max-width: 800px;
        margin: 0 auto;
        background: #000;
        padding: 30px;
        border: 2px solid #00b8ff;
        border-radius: 4px;
        box-shadow: 0 0 20px rgba(0, 255, 255, 0.2),
                    inset 0 0 20px rgba(0, 255, 255, 0.2);
        position: relative;
      }

      .back-button {
        display: inline-block;
        padding: 8px 16px;
        background: transparent;
        color: #00b8ff;
        text-decoration: none;
        border: 1px solid #00b8ff;
        font-size: 1.1em;
        margin-bottom: 20px;
      }

      h1 {
        color: #5DF2BD;
        text-align: center;
        margin-bottom: 30px;
      }

      .chapter-content {
        white-space: pre-line;
        padding: 20px;
        border: 1px solid rgba(0, 255, 255, 0.3);
      }

      .center {
        display: flex;
        justify-content: center;
      }

      .status-bar {
        background: rgba(0, 255, 255, 0.1);
        padding: 12px;
        border: 1px solid #00b8ff;
        margin-bottom: 20px;
        color: #00b8ff;
      }
    </style>
  </head>
   <body>
    <div class="container">
      <a href="/" class="back-button">RETURN TO LIBRARY</a>
      
      <h1 id="bookTitle">LOADING...</h1>
      
      <div id="bookContent" class="chapter-content">
        Accessing archives...
      </div>
    </div>

    <script>

        document.getElementById('bookTitle').textContent = book.title;
        if (book.isImage) {
          document.getElementById('bookContent').classList.add('center');


          document.getElementById('bookContent').innerHTML = `<img src="${book.content}" class="book-cover" alt="${book.title} cover">`
        } else if (book.isAudio) {
          document.getElementById('bookContent').classList.add('center');
          document.getElementById('bookContent').innerHTML = `
          <audio id="ambienceAudio" controls loop>
            <source src="${book.content}">
          </audio>`
        } else {
          document.getElementById('bookContent').textContent = book.content;
          document.title = book.title + ' - Digital Archive';
        }

    </script>
  </body>
  </body>
</html>
)rawliteral";