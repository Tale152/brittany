import { useEffect } from 'react'
import { useDispatch, useSelector } from 'react-redux'

import listData from '../../../js/persistence/listData'
import Navbar from '../../_common/Navbar'
import RedirectButton from '../../_common/navigation/RedirectButton'
import LineChart from './LineChart'

export default function DataPage() {

    const dispatch = useDispatch()
    let token = useSelector(state => state.identity.token)
    let temperature = useSelector(state => state.persistence.temperature)
    let airHumidity = useSelector(state => state.persistence.airHumidity)
    let environmentId = useSelector(state => state.environments.selected)
    let minTemp = undefined
    let maxTemp = undefined
    let minAirHum = undefined
    let maxAirHum = undefined
    let settings = useSelector(state => state.settings.list)
    if(settings.length > 0 && new Date(settings[0].expires) > new Date()){
        let current = settings[0]
        if(current.data !== undefined){
            if(current.data.temperature !== undefined){
                minTemp = current.data.temperature.min
                maxTemp = current.data.temperature.max
            }
            if(current.data.airHumidity !== undefined){
                minAirHum = current.data.airHumidity.min
                maxAirHum = current.data.airHumidity.max
            }
        }
    }

    useEffect(() => listData(token, environmentId, dispatch), [token, environmentId, dispatch])

    return (
        <div role="main" style={{ overflowX: "hidden" }}>
            <Navbar
                redirectText = { "Go to Settings" }
                redirectDestination = { "settings" }
                additionalContent = {<RedirectButton text = { "Back to Greenhouses" } destination = { "greenhouses" } />}
            />
            <LineChart title={"Temperature"} data = {temperature} min = {minTemp} max = {maxTemp} />
            <LineChart title={"Air Humidity"} data = {airHumidity} min = {minAirHum} max = {maxAirHum} />
        </div>   
    )
  
}
