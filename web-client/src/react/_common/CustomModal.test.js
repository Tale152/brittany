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
    screen.getByRole("button").click()
    expect(show).toBe(false)
})
