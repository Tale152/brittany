const persistenceServiceAddress = process.env.REACT_APP_PERSISTENCE_SERVICE_ADDRESS || 'http://localhost'
const persistenceServicePort = process.env.REACT_APP_PERSISTENCE_SERVICE_PORT || 80
export const persistenceService = persistenceServiceAddress + ":" + persistenceServicePort