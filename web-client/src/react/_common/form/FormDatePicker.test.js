import React from 'react'
import { render, screen } from '@testing-library/react'

import FormDatePicker from './FormDatePicker'
const text = "date picker text"

function renderComponent(text, selected, onChange){
    render(<FormDatePicker text = { text } selected = { selected } onChange = { onChange }/>)
}

test("Expecting text to be correct", () => {
    renderComponent(text, null, () => {})
    expect(screen.getByText(text)).toBeInTheDocument()
})

test("Expecting correct on change behaviour", () => {
    let selected = null
    renderComponent(text, selected, input => { selected = input })
    expect(selected).toBe(null)
    screen.getByRole("textbox").click()
    screen.getAllByLabelText("Choose Sunday", { exact: false })[0].click()
    expect(selected).not.toBe(null)
})
