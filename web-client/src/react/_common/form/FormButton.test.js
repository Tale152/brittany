import 'bootstrap/dist/css/bootstrap.min.css'

import React from 'react'
import { Provider } from 'react-redux'
import { createStore } from 'redux'
import { render, screen } from '@testing-library/react'

import allReducers from '../../../redux'
import FormButton from './FormButton'
const store = createStore(allReducers)
const text = "button text"

function renderButton(text, onClick){
    render(
        <Provider store={store}>
            <FormButton text = { text } onClick = { onClick }/>
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
