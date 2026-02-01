

 function Cards(props) {
    let data = props.data;
    return (
        <div className="card">
            <img src={data.image} alt="Profile" className="card-image" />
            <div className="card-info">
                <h3 className="card-name">{data.title}</h3>
                <p className="card-description">{data.description}</p>
            </div>
        </div>
    );
}

export default Cards;