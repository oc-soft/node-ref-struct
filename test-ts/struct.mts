import * as assert from 'node:assert'
import { Buffer } from 'node:buffer'
import { Struct } from 'ref-struct'
import ref from 'ref'

export function run(): void {
  assert.equal(typeof Struct, 'function')

  const TestStruct = Struct(
    [
      {
        name: 'field1',
        type: ref.types.int
      },
      {
        name: 'field2',
        type: ref.types.char
      }
  ])
  assert.equal(typeof TestStruct, 'function')

  const testInstance = new TestStruct({
    field2: 'H',
    field1: 5
  })
  assert.ok(Buffer.isBuffer(testInstance.ref()))


  assert.equal(typeof testInstance.ref().type, 'function')
}


// vi: se ts=2 sw=2 et:
