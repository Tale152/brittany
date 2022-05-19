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
import userEvent from '@testing-library/user-event'

import allReducers from '../../../../redux'
import FormInput from './FormInput'
const store = createStore(allReducers)
const text = "button text"
const placeholder = "button placeholder"

function renderButton(onChange){
    render(
        <Provider store={store}>
            <FormInput type = { "text" } text = { text } placeholder = { placeholder } onChange = { onChange }/>
        </Provider>
    )
}

test("Expecting text to be rendered", () => {
    renderButton(() => {})
    expect(screen.getByText(text)).toBeInTheDocument()
})

test("Expecting placeholder to be rendered", () => {
    renderButton(() => {})
    expect(screen.getByPlaceholderText(placeholder)).toBeInTheDocument()
})

test("Expecting value to be updated typing", () => {
    const stringToType = "hello, test!"
    let typed = ""
    renderButton(input => { typed = input })
    expect(typed).toBe("")
    userEvent.type(screen.getByPlaceholderText(placeholder), stringToType)
    expect(typed).toBe(stringToType)
})
