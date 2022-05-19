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

import 'bootstrap/dist/css/bootstrap.min.css'

import React from 'react'
import { Provider } from 'react-redux'
import { createStore } from 'redux'
import { render, screen } from '@testing-library/react'

import allReducers from '../../redux'
import CustomCenteredButton from './CustomCenteredButton'
const store = createStore(allReducers)
const text = "button text"

function renderButton(text, onClick){
    render(
        <Provider store={store}>
            <CustomCenteredButton text = { text } onClick = { onClick }/>
        </Provider>
    )
}

test("Expecting text to be correct", () => {
    renderButton(text, () => {})
    expect(screen.getByText(text)).toBeInTheDocument()
})

test("Expecting button to execute on click", () => {
    let flag = false
    renderButton(text, () => { flag = true })
    expect(flag).toBe(false)
    screen.getByText(text).click()
    expect(flag).toBe(true)
})
