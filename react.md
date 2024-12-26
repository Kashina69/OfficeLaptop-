# System design of a distributed chat system

# Understanding web socket and redis

# Fast backend

```js
app.get("/products", async (req, res) => {

  let products;
  if (nodeCache.has("products")) {
    products = JSON.parse(nodeCache.get("products"));
  } else {
    const products = await Product.find({}); nodeCache.set("products", JSON.stringify(products),60 // Standard time to live);
  }

  return res.json({
    success: true,
    products,
  });

});

// npm i node-cache

import NodeCache from "node-cache";

const app = express();
const nodeCache = new NodeCache({
  stdTTL: 60, //Standard time to live
});
```

# Node.js working 

```js

const http = require("http")
const server = http.createServer((req,res)=>{

})

const PORT = 4000

server.listen(PORT,()=>{
    console.log("Hello world");
})

```


