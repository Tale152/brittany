import { render, screen } from '@testing-library/react'
import ExampleTextProps from './ExampleTextProps'

test('Expecting to ExampleTextProps to render the text passed by props', () => {
  render(<ExampleTextProps text={"za warudo"}/>)
  const textPropsContent = screen.getByText(/za warudo/i)
  expect(textPropsContent).toBeInTheDocument()
})
