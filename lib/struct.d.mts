import type { TypeBase } from 'ref'
import type { Buffer } from 'node:buffer'

export type OrderedStructTypeParam = {
  names: string[]
  fields: { [name: string]: TypeBase }
}

export type StructTypeParam = 
  OrderedStructTypeParam | { [key: string]: TypeBase }

/**
 * struct type interface 
 */
export interface StructType {
  /**
   * create StructType instance
   */
  (arg: Buffer | StructTypeParam, data?: StructTypeParam): StructType 

  /**
   * create StructType instance
   */
  new (arg: Buffer | StructParam, data?: StructParam): StructType 

  /**
   * struct size
   */
  get size(): number

  /**
   * memory layout alignment
   */
  get alignment(): number


  /**
   * define new field
   */
  defineProperty(name: string, type: TypeBase): void

  /**
   * indirection count
   */
  indirection: number

  /**
   * packing status
   */
  isPacked: boolean

  /**
   * get Struct type from buffer
   * @param {Buffer} buffer
   * @param {number=} offset
   * @return StructType
   */
  get(buffer: Buffer, offset?: number): StructType

  /**
   * set struct into buffer
   * @param {Buffer} buffer
   * @param {number} offset
   * @param {StructType | StructParam}
   */
  set(buffer: Buffer,
    offset: number, value: StructType | StructTypeParam): void 

  /**
   * fields which are contained in this struct
   */
  fields: { [key: string]: {type: TypeBase} }

  /**
   * field names
   */
  names: string[]

  /**
   * convert object
   * @return {object}
   */
  toObject(): object

  /**
   * convert json object
   * @return {object}
   */
  toJson(): object

  /**
   * output to console inspected result
   */
  inspect(): void

  /**
   * convert buffer
   */
  ref(): BufferStruct
}

export class BufferStruct extends Buffer {
  type: StructType 
}


export type ObjectStructParam = {
  type: TypeBase 
  name: string
}

export type ArrayStructParam = [ TypeBase, string ]

export type StructParam = ObjectStructParam | ArrayStructParam

export type ObjectStructParams = {
  names: string[]
  fileds: { [name: string]: TypeBase }
}

/**
 * create struct
 * @param {StructParam[] | ObjectStructParams} args
 */
export function Struct(
  args?: StructParam[] | ObjectStructParams): StructType


export { Struct as default }

// vi: se ts=2 sw=2 et:
