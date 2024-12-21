
import { createRequire } from 'node:module'

const require = createRequire(import.meta.url)
const Struct = require('./struct.js')


export { Struct as default, Struct }

// vi: se ts=2 sw=2 et:
