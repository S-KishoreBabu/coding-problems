import Cards from '../Cards/Cards.jsx';
import flamesImage from '../assets/flames2.jpeg';
import astroImage from '../assets/astrology.jpeg';
import matrimonyImage from '../assets/matrimony2.jpeg';

const cardData = [
    {
        image : flamesImage,
        title: "flames",
        description: "Discover your compatibility with others through the ancient art of FLAMES."
    },{
        image : astroImage,
        title: "astrology",
        description: "Explore the mysteries of the stars and their influence on your life."
    },{
        image : matrimonyImage,
        title: "matrimony",
        description: "Find your perfect match and build a lasting relationship."
    },{
        image: astroImage,
        title:"astrology",
        description: "Explore the mysteries of the stars and their influence on your life."
    }
]

const cardList = cardData.map((info)=>{
    return <Cards data = {info}/>
})
function CardsWrapper() {
    return (
        <div className="cards-wrapper">
            {cardList}
        </div>
    );
}
export default CardsWrapper;