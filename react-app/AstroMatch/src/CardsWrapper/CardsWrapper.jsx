import Cards from '../Cards/Cards.jsx';
import flamesImage from '../assets/flames2.jpeg';
import astroImage from '../assets/astrology.jpeg';
import matrimonyImage from '../assets/matrimony2.jpeg';

const cardData = [
    {   
        key : 1,
        image : flamesImage,
        title: "flames",
        description: "Discover your compatibility with others through the ancient art of FLAMES."
    },{
        key : 2,
        image : astroImage,
        title: "astrology",
        description: "Explore the mysteries of the stars and their influence on your life."
    },{
        key : 3,
        image : matrimonyImage,
        title: "matrimony",
        description: "Find your perfect match and build a lasting relationship."
    },{
        key : 4,
        image: astroImage,
        title:"astrology",
        description: "Explore the mysteries of the stars and their influence on your life."
    }
]

const cardList = cardData.map((info)=>{
    return <Cards data = {info}/>
})

console.log(cardList);
function CardsWrapper() {
    return (
        <div className="cards-wrapper">
            {cardList}
        </div>
    );
}
export default CardsWrapper;