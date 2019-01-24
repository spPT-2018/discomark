using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Rotate : MonoBehaviour
{
    public float Speed1;
    public float Speed2;
    public float Speed3;
	
	// Update is called once per frame
	void Update () {
		this.transform.Rotate(Vector3.down, Speed1 * Time.deltaTime);
		this.transform.Rotate(Vector3.left, Speed2 * Time.deltaTime);
		this.transform.Rotate(Vector3.forward, Speed3 * Time.deltaTime);
	}
}
