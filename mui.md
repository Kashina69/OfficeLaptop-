# MUI

## Theme

```tsx
import { createTheme, ThemeProvider } from "@mui/material/styles";

const theme = createTheme({
  palette: {
    primary: { main: "#1976d2" },
    secondary: { main: "#dc004e" },
  },
  typography: {
    fontFamily: "Roboto, Arial",
  },
});

<ThemeProvider theme={theme}>/* Components Here */</ThemeProvider>;
```

## Grid

```tsx
import { Typography, Grid, Paper } from "@mui/material";

<Grid container spacing={2}>
  <Grid item xs={12}>
    <Typography variant="h4" color="primary">
      Welcome to MUI
    </Typography>
  </Grid>
  <Grid item xs={6}>
    <Typography>Left Column</Typography>
  </Grid>
  <Grid item xs={6}>
    <Typography>Right Column</Typography>
  </Grid>
</Grid>;

<Grid container>
  <Grid item xs={12} s={6} md={3}>
    <Paper>1</Paper>
  </Grid>
  <Grid item xs={12} s={6} md={3}>
    <Paper>2</Paper>
  </Grid>
  <Grid item xs={12} s={6} md={3}>
    <Paper>3</Paper>
  </Grid>
  <Grid item xs={12} s={6} md={3}>
    <Paper>4</Paper>
  </Grid>
</Grid>;
```

## Button

```tsx
import { Button } from "@mui/material";

<Button variant="contained" color="primary">
  Contained
</Button>;
<Button variant="outlined" color="secondary">
  Outlined
</Button>;
<Button variant="text" disabled>
  Disabled
</Button>;
```

## Forms

```tsx
import { TextField, Checkbox, FormControlLabel } from "@mui/material";

// Controlled TextField
const [value, setValue] = React.useState("");

<TextField
  label="Name"
  value={value}
  onChange={(e) => setValue(e.target.value)}
/>;

// Checkbox
<FormControlLabel control={<Checkbox />} label="Accept Terms" />;
```

## Navigation / Drawer

```tsx
import React from "react";
import { Drawer, List, ListItem, ListItemText } from "@mui/material";

const AppDrawer: React.FC = () => {
  const [open, setOpen] = React.useState(false);

  return (
    <>
      <button onClick={() => setOpen(true)}>Open Drawer</button>
      <Drawer anchor="left" open={open} onClose={() => setOpen(false)}>
        <List>
          <ListItem button>
            <ListItemText primary="Home" />
          </ListItem>
          <ListItem button>
            <ListItemText primary="About" />
          </ListItem>
        </List>
      </Drawer>
    </>
  );
};
```

## Dialog

```tsx
import React from "react";
import { Dialog, DialogTitle, DialogActions, Button } from "@mui/material";

const MyDialog: React.FC = () => {
  const [open, setOpen] = React.useState(false);

  return (
    <>
      <Button onClick={() => setOpen(true)}>Open Dialog</Button>
      <Dialog open={open} onClose={() => setOpen(false)}>
        <DialogTitle>Are you sure?</DialogTitle>
        <DialogActions>
          <Button onClick={() => setOpen(false)}>Cancel</Button>
          <Button onClick={() => alert("Confirmed")}>Confirm</Button>
        </DialogActions>
      </Dialog>
    </>
  );
};
```

## Using sx props

```tsx
<Box sx={{ bgcolor: "primary.main", color: "white", p: 2 }}>Custom Box</Box>
```

## Responsive Design

```tsx
<Grid container spacing={2}>
  <Grid item xs={12} sm={6}>
    <Typography>
      Full-width on small screens, half-width on larger screens.
    </Typography>
  </Grid>
</Grid>
```

## Net ninja

### Make Style

```jsx
import { makeStyles } from "@material-ui/core/makeStyles";

const useStyles = makeStyles({
  btn: {
    fontSize: 60,
    backgroundS: "violet",
    "&hover":{
      backgroundColor:"blue"
    }
  },
  title:{
    textDecoration:"underline",
    marginBottom:10
  }
});
const classes = useStyles();
<Button className = {classes.btn}>
```

### Custom themes

```jsx
import {createMuiTheme, ThemeProvider}from "@material-ui/core";

const theme = createMuiTheme({
  palette:{
    primary:{
      main:"#fefefe"
    },
    secondary: purple
  }
});
App.jsx
return (
  <ThemeProvider theme={theme}>
    <Components/>
  </ThemeProvider>
)
```
