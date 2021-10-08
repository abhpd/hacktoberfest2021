import React from "react";
import { BrowserRouter, Redirect, Route, Switch } from "react-router-dom";
import { ThemeProvider } from "styled-components";
import { useTheme } from "./ThemeManager";
import Nav from "./Components/Nav";
import About from "./Components/About";
import NotFound from "./Components/NotFound";
import Home from "./Components/Home";

import { Wrapper } from "./StyleComponents/Wrapper";
import Contact from "./Components/Contact";

const App: React.FC = () => {
  const theme = useTheme();

  return (
    <ThemeProvider theme={{ mode: theme.mode }}>
      <BrowserRouter>
        <Nav />
        <Wrapper>
          <Switch>
            <Route path="/" exact component={Home} />
            <Route path="/about" component={About} exact />
            <Route path="/contact" component={Contact} exact />
            <Route path="/notFound" exact component={NotFound} />
            <Redirect from="/" to="/notFound" />
          </Switch>
        </Wrapper>
      </BrowserRouter>
    </ThemeProvider>
  );
};

export default App;
