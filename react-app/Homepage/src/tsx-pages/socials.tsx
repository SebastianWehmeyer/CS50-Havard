import Navbar from '../components/navbar.jsx'
import Footer from "../components/footer.jsx"
import Slider from "../components/slider.jsx"

export default function Index () {

  const slides = [
    { title: "Github", url: "http://localhost:5173/github.png", linkTo: "https://github.com/SebastianWehmeyer", },
    { title: "Linkedin", url: "http://localhost:5173/linkedin.png", linkTo: "https://www.linkedin.com/in/sebastian-wehmeyer-6074b1287/", },
    { title: "Instagram", url: "http://localhost:5173/instagram.png", linkTo: "https://www.instagram.com/xseb22/", },
    { title: "Twitter", url: "http://localhost:5173/twitter.png", linkTo: "https://www.twitter.com/xseb22/", },
    { title: "Twitch", url: "http://localhost:5173/twitch.png", linkTo: "https://www.twitch.tv/xseb22", },
    { title: "Secret", url: "http://localhost:5173/emoji.png", linkTo: "https://www.youtube.com/watch?v=dQw4w9WgXcQ", },
  ];

  const containerStyles = {
    width: "500px",
    height: "280px",
    margin: "0 auto",
  };


    return(
        <>
            <div>
              <Navbar />  
            </div>
            <div style={containerStyles}>
              <Slider slides={slides} />
            </div>
            <div>
              <Footer />  
            </div>
        </>
    )
}