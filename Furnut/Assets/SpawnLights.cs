using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class SpawnLights : MonoBehaviour
{
    public int NumberOfLights;
    public float MinX;
    public float MaxX;
    public float MinY;
    public float MaxY;
    public float MinZ;
    public float MaxZ;
    public GameObject LightPrefab;

	// Use this for initialization
	void Start () {
	    for (int i = 0; i < NumberOfLights; i++)
	    {
	        var light = Instantiate(LightPrefab);
	        light.transform.position =
	            new Vector3(Random.Range(MinX, MaxX), Random.Range(MinY, MaxY), Random.Range(MinZ, MaxZ));
            var lightComp = light.GetComponent<Light>();
	        lightComp.color = new Color(Random.Range(0f,1f), Random.Range(0f,1f), Random.Range(0f,1f));
	        //lightComp.range = Vector3.Distance(transform.position, light.transform.position) + 5;
	        lightComp.spotAngle= Random.Range(0f, 30f);
            //lightComp.transform.LookAt(transform);

	        var rotate = lightComp.GetComponent<Rotate>();
	        rotate.Speed1 = Random.Range(0f, 20f);
	        rotate.Speed2 = Random.Range(0f, 20f);
	        rotate.Speed3 = Random.Range(0f, 20f);
	    }
	}
}
