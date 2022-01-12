import 'chart.js/auto'
import { Line } from 'react-chartjs-2'
import Row from 'react-bootstrap/Row'

export default function LineChart(props){

    let options = {
        scales:{
            x: {
                display: false
            }
        },
        responsive: true,
        plugins: {
            title: {
                display: true,
                text: props.title,
            },
        },
    }

    let data = {
        labels: props.data.map(t => t.timestamp),
        datasets: [
            {
                id: 1,
                label: 'Data',
                data: props.data.map(t => t.value),
                borderColor: 'black',
                backgroundColor: 'black',
                pointRadius: 1,
            }
        ],
    }

    if (props.min !== undefined && props.max !== undefined){
        data.datasets.push({
            id: 2,
            label: 'Min',
            data: props.data.map(v => props.min),
            borderColor: 'blue',
            backgroundColor: 'blue',
            pointRadius: 1,
        })
        data.datasets.push({
            id: 3,
            label: 'Max',
            data: props.data.map(v => props.max),
            borderColor: 'red',
            backgroundColor: 'red',
            pointRadius: 1,
        })
    }

    return (
        <Row className="d-flex justify-content-center">
            <div className="my-5 container col-9">
                <Line
                    datasetIdKey='id'
                    data={data}
                    options={options}
                />
            </div>
        </Row>
    )
}