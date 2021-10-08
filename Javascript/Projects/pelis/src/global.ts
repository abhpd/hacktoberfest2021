import { createGlobalStyle } from "styled-components";

export const GlobalStyle = createGlobalStyle`
    *{
        margin: 0;
        padding: 0;
        outline:0;
        font-size: calc(10px + 1vmin);
        box-sizing:border-box;
    }
    #root{
        margin:0 auto;
    }
 `;
