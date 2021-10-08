import styled from "styled-components";
import { Title } from "../StyleComponents/Title";
import * as themeConf from "../theme";
import { FaGithub, FaInstagram, FaLinkedin, FaTwitter } from "react-icons/fa";

const CardWrapper = styled.div`
  background-color: ${themeConf.inputBackgroundColor};
  box-shadow: 0px 0px 4px ${themeConf.boxShadowColor};
  padding: 3em;
  border-radius: 0.1em;
`;

const CardImage = styled.img`
  width: 80%;
  border-radius: 50%;
  margin-bottom: 0.2em;
`;

const SubTitle = styled.h5`
  color: ${themeConf.textSecondaryColor};
  font-size: 1.2em;
  margin-bottom: 0.9em;
`;

const CardLink = styled.a`
  > svg {
    margin-right: 0.7em;
    font-size: 1.5em;
    color: ${themeConf.textColor};
  }
`;

export default function CardContact(): React.ReactElement {
  return (
    <CardWrapper>
      <CardImage
        src="https://media-exp1.licdn.com/dms/image/C5603AQFVU4InjpmjZw/profile-displayphoto-shrink_200_200/0/1594923008451?e=1638403200&v=beta&t=ZdcYVwaQu_I-K1wQSDqZ6werKJkhpxhuaEAiMxCDjgk"
        alt="Imagen de perfil de Jordan Jaramillo"
      />
      <Title>Jordan Jaramillo</Title>
      <SubTitle>Desarrollador FullStack Js | Php</SubTitle>
      <div>
        <CardLink
          target="_blank"
          href="https://www.linkedin.com/in/jordanrjdev"
        >
          <FaLinkedin />
        </CardLink>
        <CardLink target="_blank" href="https://github.com/jordanrjdev">
          <FaGithub />
        </CardLink>
        <CardLink target="_blank" href="https://twitter.com/jordanrjdev">
          <FaTwitter />
        </CardLink>
        <CardLink target="_blank" href="https://instagram.com/vednadroj">
          <FaInstagram />
        </CardLink>
      </div>
    </CardWrapper>
  );
}
