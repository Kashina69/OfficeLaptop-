```js
function Login(){
    const [username, setUsername] = useState("")
    const [password, setPassword] = useState("")

    const handelSubmit =(e)=>{

    }
    return(
        <>
        h1 Login page
        input for user name and password
        where value = {username or password} varibale 
        and onChange{(e)=>setUsername(e.target.value) or setPassword(e.target.value)}
        </>
    )
}
```

# Context API

```js
// src/context/UserContext.js

import React from "react";

const  UserContext = React.createContext();

export default UserContext;

// src/context/UserContextProvide.jsx 
// this is a wrapper 

import React from "react";

import UserContext from "./UserContext.js"

const UserContextProvider = ({children}) =>{
    const [user, setUser] = setState
}

export default UserContextProvide;
```