import { render, screen, act, fireEvent } from '@testing-library/react'
import App from './App'

test('Messing arround', async () => {
  render(<App />)
  const flagButton = screen.getByText(/false - 0/i)
  expect(flagButton).toBeInTheDocument()
  flagButton.click()
  const flagButtonClicked = screen.getByText(/true - 1/i)
  expect(flagButtonClicked).toBeInTheDocument()
  const homepageButton = screen.getByText("Homepage")
  expect(homepageButton).toBeInTheDocument()
  await fireEvent.click(homepageButton)
  const authenticationButton = screen.getByText("Authentication")
  expect(authenticationButton).toBeInTheDocument()
  await fireEvent.click(authenticationButton)
  const flagButtonAgain = screen.getByText(/true - 0/i)
  expect(flagButtonAgain).toBeInTheDocument()
})
