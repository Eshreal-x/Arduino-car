
char webpage[] PROGMEM = R"=====(
  <html>
    <head>
      <script>
        var Socket;
        
        function init() {
          Socket = new WebSocket('ws://' + window.location.hostname + ':81/');
         // Socket.onmessage = function(event){
           // document.getElementById("rxConsole").value += event.data;
         // }
        }

        document.addEventListener("keydown", function(event) {
          if (event.keyCode == 37) {//left
            console.log("left was pressed!");
            Socket.send('0+1');
          }
          if (event.keyCode == 38) {//up
            console.log("up was pressed!");
            Socket.send('1+1');
          }
          if (event.keyCode == 39) {//right
            console.log("right was pressed!");
            Socket.send('2+1');
          }
          if (event.keyCode == 40) {//down
            console.log("down was pressed!");
            Socket.send('3+1');
          }
        });

        
        document.addEventListener("keyup", function(event) {
          if (event.keyCode == 37) {//left
            console.log("left was pressed!");
            Socket.send('0+0');
          }
          if (event.keyCode == 38) {//up
            console.log("up was pressed!");
            Socket.send('1+0');
          }
          if (event.keyCode == 39) {//right
            console.log("right was pressed!");
            Socket.send('2+0');
          }
          if (event.keyCode == 40) {//down
            console.log("down was pressed!");
            Socket.send('3+0');
          }
        });


      
      </script>
    </head>
      <body onload="javascript:init()">
        <!--<div>
          <textarea id="rxConsole"></textarea>
        </div>
        <hr/>
        <div>
          <input type="text" id="txBar" onkeydown="if(event.keyCode == 13) sendText();" />
        </div>
        <hr/>
        <div>
          <input type="range" min="0" max="1023" value="512" id="brightness" oninput="sendBrightness()" />
        </div>  
        
    
        <div class="box"></div>-->
    
    
    
    
      </body>
    </html>
)=====";