import 'bootstrap/dist/css/bootstrap.min.css'

import React from 'react'

import { Provider } from 'react-redux'
import { createStore } from 'redux'
import allReducers from '../../redux'

const store = createStore(allReducers)
import { render, screen } from '@testing-library/react'
import ExampleFlagButton from './ExampleFlagButton'

test("Expecting ExampleFlagButton to do it's fucking job", () => {
  render(<Provider store={store}><ExampleFlagButton/></Provider>)
  const flagButton = screen.getByText(/false - 0/i)
  expect(flagButton).toBeInTheDocument()
  flagButton.click()
  const flagButtonClicked = screen.getByText(/true - 1/i)
  expect(flagButtonClicked).toBeInTheDocument()
})
