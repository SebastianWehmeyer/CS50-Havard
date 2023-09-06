import { useState } from "react";
import "../css/slider.css"

const slideStyles = {
    width: "250px",
    height: "250px",
    backgroundSize: "cover",
    backgroundPosition: "center",
    backgroundColor: "green",
    justifyContent: "center",
    marginTop: "10px",
    marginBottom: "25px",
    marginLeft: "25px",
};

const Slider = ({ slides }) => {

  const [currentIndex, setCurrentIndex] = useState(0);

  const goToPrevious = () => {
    const isFirstSlide = currentIndex === 0;
    const newIndex = isFirstSlide ? slides.length - 1 : currentIndex - 1;
    setCurrentIndex(newIndex);
  };

  const goToNext = () => {
    const isLastSlide = currentIndex === slides.length - 1;
    const newIndex = isLastSlide ? 0 : currentIndex + 1;
    setCurrentIndex(newIndex);
  };

  const goToSlide = (slideIndex) => {
    setCurrentIndex(slideIndex);
  };

  const slideStylesWidthBackground = {
    ...slideStyles,
    backgroundImage: `url(${slides[currentIndex].url})`,
  };

  return (
    <div className="sliderStyles">
      <div className="arrowContainer">
        <button onClick={goToPrevious} className="leftArrowStyles">
          ❰
        </button>
        <button onClick={goToNext} className="rightArrowStyles">
          ❱
        </button>
      </div>
      <div className="parent">
        <fieldset>
            <legend>{slides[currentIndex].title}</legend>
            <a href={slides[currentIndex].linkTo} target="_blank">
                <img src={slides[currentIndex].url} className="slideStyles" />
            </a>
        </fieldset>
      </div>
      
      
      <div className="dotsContainerStyles">
        {slides.map((slide, slideIndex) => (
          <button
            className="dotStyle"
            key={slideIndex}
            onClick={() => goToSlide(slideIndex)}
          >
            ●
          </button>
        ))}
      </div>
    </div>
  );
};

export default Slider;
