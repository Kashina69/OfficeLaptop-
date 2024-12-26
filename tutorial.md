# React Router

## Backend

```js
import express from "express";

const app = express();

app.get("app/products", (req, res) => {
  const products = [];

  // http://localhost:3000/api/products?search=metal
  if (req.query.search) {
    const filterProducts = products.filter((product) =>
      product.name.includes(req.query.search)
    );
    res.send(filterProducts);
    return;
  }

  setTimeout(() => {
    res.send(products);
  }, 3000);
});

const port = process.env.PORT || 3000;
app.listen(port);
```

## React app

```jsx
function App() {

  const [products, setProducts] = useState([]);
  const [error, setError] = useState(false);
  const [loading, setLoading] = useState(false);
  useEffect(() => {
    (async () => {
      try {
        setLoading(true);
        setError(false);
        const response = await axios.get("/api/products");
        console.log(response.data);
        setProducts(response.data);
        setLoading(false);
      } catch (error) {
        setError(true);
        setLoading(false);
      }
    })();
  }, []);

const [products, error, loading] = customReactQuery('/api/produts')
if(error){
    return(something went wrong)
}
if(loading){
    return(Loading...)
}

  return <>{products.length}</>;
}

const customReactQuery = (urlPath) =>{

}
```
