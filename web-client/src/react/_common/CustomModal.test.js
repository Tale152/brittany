import 'bootstrap/dist/css/bootstrap.min.css'

import React from 'react'
import { render, screen } from '@testing-library/react'

import CustomModal from './CustomModal'
const titleText = "title"
const bodyText = "body"

function renderModal(title, body, show, onHide){
    render(
        <CustomModal title = { title } body = { body } show = { show } onHide = { onHide }/>
    )
}

test("Expecting content to be rendered on modal shown", () => {
    renderModal(titleText, <p>{ bodyText }</p>, true, () => {})
    expect(screen.getByText(titleText)).toBeInTheDocument()
    expect(screen.getByText(bodyText)).toBeInTheDocument()
})

test("Expecting content to not be rendered on modal not shown", () => {
    renderModal(titleText, <p>{ bodyText }</p>, false, () => {})
    const title = screen.queryByText(titleText)
    expect(title).not.toBeInTheDocument()
    const body = screen.queryByText(bodyText)
    expect(body).not.toBeInTheDocument()
})

test("Expecting modal to be closable", () => {
    let show = true
    renderModal(titleText, <p>{ bodyText }</p>, show, () => { show = false })
    expect(screen.getByText(bodyText)).toBeInTheDocument()
    //TODO
})
