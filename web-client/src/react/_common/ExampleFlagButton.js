import { useState } from 'react'
import { useSelector, useDispatch } from 'react-redux'
import { setFlag } from '../../redux/example/actions'
import Button from 'react-bootstrap/Button'

export default function ExampleFlagButton(props) {

  const dispatch = useDispatch()
  //redux state
  let flag = useSelector(state => state.example.flag)
  //ExampleFlagButton internal state
  const [counter, setCounter] = useState(0)

  return (
    <Button
      style={{opacity: "0.4"}}
      className="col-lg-12 mt-3"
      variant={flag === false ? "danger" : "primary"}
      size="lg"
      block
      onClick={() => {
        dispatch(setFlag(!flag))
        setCounter(counter + 1)
      }}
    >
      {flag + " - " + counter}
    </Button>
  )
}
