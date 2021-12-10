import Button from 'react-bootstrap/Button'

export default function AuthForm(props) {

    return (
        <Button
          onClick={props.onClick}
        >
          Login
        </Button>
    )

}
