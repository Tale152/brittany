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
