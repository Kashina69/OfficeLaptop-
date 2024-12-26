# Chat App

## server.js

```js
const app = require("express")();
const server = require("http").createServer(app);
const io = require("socket.io")(server, {
  cors: {
    origin: "http://localhost:3000",
  },
});

io.on("connection", (socket) => {
  socket.on("chat", (payload) => {
    io.emit("chat", payload);
  });
});
server.listen(5500, () => {
  console.log("The server is listning on port 5500");
});
```

## App.js

```js
// npm i socket.io-client nanoid

import {useState, useEffect} from "react";
import io from "socket.io-client";
import {nanoid} from "nanoid";

const socket = io.connect("localhost://5500");

function sendChat(e) {
        e.preventDefault()
        socket.emit("chat", {message})
        setMessage("")
    }

function App() {
    const [message, setMessage] = useState("")
    const [chat, setChat] = useState("")

    useEffect(()=>{
        socket.on("chat",(payload)=>{
          setChat[...chat, payload]
        })
    })
    return(
        {chat.map((payload, index)=>{
            return(
              p key={index} {payload.message}
            )
        })}
        form onSubmit={sendChat}
        input value = {message}
        onChange = {(e)=>{
            setMessage(e.target.value)
        }}
        button type = "submit"

    )
}
```

```js

```

```js

```

```js

```
