/*
 * Copyright (C) 2022 Angelo Filaseta, Alessandro Talmi, Elisa Tronetti
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

var initialState = {
    temperature: [],
    airHumidity: []
}

const persistenceReducer = (state = initialState, action) => {
    switch(action.type){
        case 'SET_TEMPERATURE': return Object.assign({}, state, {
            temperature: action.payload
        })
        case 'SET_AIR_HUMIDITY': return Object.assign({}, state, {
            airHumidity: action.payload
        })
        default: return state;
    }
}
export default persistenceReducer
