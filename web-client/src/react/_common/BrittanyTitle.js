import logo from "../../plant.png"

export default function BrittanyTitle(){
    return (
        <>
            <div style={{ height: 100, display: "flex", alignItem: "center", justifyContent: "center"}}>
                <img alt="logo" src={logo} />
            </div>
            <h1 className="d-flex justify-content-center">Brittany dashboard</h1>
        </>
    )
}
