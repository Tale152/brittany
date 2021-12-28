import { render, screen, act, fireEvent } from '@testing-library/react'
import App from './App'

test('Mock test', async () => {
  render(<App />)
  expect(1).toBe(1)
})
