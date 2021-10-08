import theme from "styled-theming";

export const backgroundColor: theme.ThemeSet = theme("mode", {
  light: "#fafafa",
  dark: "#0e0f11",
});

export const navBackgroundColor: theme.ThemeSet = theme("mode", {
  light: "rgba(255, 255, 255, .97)",
  dark: "rgba(0,0,0,.97)",
});

export const textColor: theme.ThemeSet = theme("mode", {
  light: "#191919",
  dark: "#fafafa",
});

export const textSecondaryColor: theme.ThemeSet = theme("mode", {
  light: "#2e86de",
  dark: "#c44569",
});

export const buttonBackgroundColor = theme("mode", {
  light: "#222",
  dark: "#eee",
});

export const buttonTextColor = theme("mode", {
  light: "#eee",
  dark: "#222",
});

export const borderColor = theme("mode", {
  light: "#222",
  dark: "#eee",
});

export const inputBackgroundColor = theme("mode", {
  light: "#c8d6e5",
  dark: "#333",
});

export const boxShadowColor = theme("mode", {
  light: "#ccc",
  dark: "#57606f",
});

export const navHeight = "85px";

export const navPadding = "20px";
